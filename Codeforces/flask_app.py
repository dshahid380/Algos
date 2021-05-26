import flask
from flask import request, jsonify

app = flask.Flask(__name__)
app.config["DEBUG"] = True


# Logic/url etc...

@app.route("/", methods=["GET"])
def firstPage():
    return "Hi I am Adrika Roy"


@app.route("/about", methods=["GET"])
def about():
    return 'This is about page'


@app.route("/api", methods=["POST"])
def post_api():
    print("This is request body")
    content = request.json
    print(content)
    return "api response id: "


# End of logic
if __name__ == '__main__':
    app.run()
