from flask import Flask, render_template, redirect, request

app = Flask(__name__)


@app.route('/')
@app.route('/home')
def home():
    return render_template('home.html')



@app.route('/work_experience')
def experience():
    return render_template('experience.html')

@app.route('/personal_projects')
def personal_projects():
    return render_template('personal_project.html')

@app.route('/', methods=['GET', 'POST'])
def button():
    if request.method == 'POST':
        if request.form.get('experience') == "WORK EXPERIENCE":
            return redirect('/work_experience')
        elif request.form.get('projects') == "PERSONAL PROJECTS":
            return redirect('/personal_projects')
        elif request.form.get('contact') == "GET IN CONTACT":
            return redirect('/contact')


@app.route('/contact')
def contact():
    return render_template('contact.html')



if __name__ == '__main__':
    app.run(debug=True)
