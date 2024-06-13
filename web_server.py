from flask import Flask, request, jsonify

app =Flask(__name__)

def receive_data() :
    data = request.json
    print(data)


if __name__ == '__main__' :
    app.run(host='127.0.0.1', port = 5000)
    receive_data()


