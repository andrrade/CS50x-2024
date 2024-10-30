from flask import Flask, render_template, request

app = Flask(__name__)

SPORTS = ["Basketball", "Football", "Soccer", "Ultimate Frisbee"]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():
    if not request.form.get("name") or not request.form.get("sport"):
        # return "failure"
        return render_template("failure.html")
    # return "success"
    return render_template("success.html")
