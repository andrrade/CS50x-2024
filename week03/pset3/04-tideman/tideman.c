#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool creates_cycle(int winner, int loser);
bool has_path(int start, int end); // Function to check for path in graph

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // Loop through each candidate's rank
    for (int i = 0; i < candidate_count; i++)
    {
        // Loop through candidates that are ranked lower than the current candidate
        for (int j = i + 1; j < candidate_count; j++)
        {
            // Update preferences: i is preferred over j
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0; // Reinicie a contagem de pares
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // Evite comparar o mesmo candidato
            if (i != j)
            {
                // Verifique se o candidato i é preferido ao candidato j
                if (preferences[i][j] > preferences[j][i])
                {
                    // Adicione o par ao array de pares
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                    pair_count++; // Incrementa o contador de pares

                    // Certifique-se de não exceder o tamanho máximo
                    if (pair_count >= MAX * (MAX - 1) / 2)
                    {
                        return; // Não adicione mais pares se já estiver cheio
                    }
                }
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            int strengthA = preferences[pairs[j].winner][pairs[j].loser];
            int strengthB = preferences[pairs[j + 1].winner][pairs[j + 1].loser];

            // Se o par j é mais fraco que o par j+1, troque
            if (strengthA < strengthB)
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        // Verifique se adicionar o par não cria um ciclo
        // Se não houver ciclo, trancamos o par
        if (!creates_cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Função auxiliar para verificar a criação de ciclos
bool creates_cycle(int winner, int loser)
{
    // Verifique se há um caminho do loser até o winner
    return has_path(loser, winner);
}

// Função para verificar se há um caminho em um grafo
bool has_path(int start, int end)
{
    // Cria um array para marcar visitados
    bool visited[MAX] = {false};

    // Cria uma fila para a busca
    int stack[MAX], top = 0;
    stack[top++] = start;

    // Enquanto houver elementos na pilha
    while (top > 0)
    {
        int current = stack[--top];
        // Se já visitamos este candidato, continue
        if (visited[current])
        {
            continue;
        }

        // Marque como visitado
        visited[current] = true;

        // Verifique se há um caminho
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[current][i])
            {
                // Se encontramos um caminho para o vencedor, retorne verdadeiro
                if (i == end)
                {
                    return true;
                }
                // Adicione o candidato à pilha para continuar a busca
                stack[top++] = i;
            }
        }
    }
    return false; // Não há caminho do loser ao winner
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool is_winner = true; // Assume que é o vencedor
        for (int j = 0; j < candidate_count; j++)
        {
            // Se houver alguém que derrotou este candidato, ele não é o vencedor
            if (locked[j][i])
            {
                is_winner = false;
                break; // Não é um vencedor
            }
        }
        if (is_winner)
        {
            printf("%s\n", candidates[i]); // Imprime o nome do vencedor
            return;
        }
    }
    return;
}
