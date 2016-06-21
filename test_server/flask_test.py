#!/usr/bin/env python3
# coding=utf-8

from flask import Flask
import logging
app = Flask(__name__)

log = logging.getLogger('werkzeug')
log.setLevel(logging.ERROR)


@app.route('/')
def hello_world():
    return 'Hello World!'

if __name__ == '__main__':
    app.run(port=8888, debug=False)
