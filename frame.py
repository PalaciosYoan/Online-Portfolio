from flask import Flask, render_template, redirect

app = Flask(__name__)

@app.route('/')
@app.route('/home')
def home():
    return render_template('index.html')

@app.route('/resume')
def resume():
    return render_template('base.html')

@app.route('/personal_projects')
def personal_projects():
    return render_template('base.html')

if __name__=='__main__':
    app.run(debug=True)
