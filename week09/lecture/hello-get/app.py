from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    # name = request.args.get("name", None)
    # name = request.args.get("name", "world")
    # return render_template("01-index.html", name=name) # name_of_paramter=value_of_parmter
    return render_template("index.html")

@app.route("/greet", methods=["POST"])
def greet():
    name = request.form.get("name", "world")
    return render_template("greet.html", name=name)

