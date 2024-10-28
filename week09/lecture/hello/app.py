from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("01-index.html")
