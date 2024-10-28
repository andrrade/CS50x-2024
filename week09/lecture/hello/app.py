from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    name = request.args["name"]
    return render_template("01-index.html", placeholder=name)
