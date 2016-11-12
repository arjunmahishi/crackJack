from django.shortcuts import render
from django.conf import settings
import random
from django.core.files.storage import FileSystemStorage

IMAGES = ['super.jpg', 'hq.jpg', 'bg.jpg', 'jd.jpg']

def getBG(IMAGES):
	tempBG = ""
	
	while (True):
		bg = random.choice(IMAGES)
		if bg != tempBG:
			break

	return bg

class Question:
	def __init__(self, pset):
		self.problem = pset[0]
		self.disc = pset[1]
		self.ind = pset[2]

def index(requests):
	lunch = {
		'bg' : 'anon.jpg',
		'head' : 'Home'
	}
	return render(requests, 'land.html', lunch)

def home(requests):
	lunch = {
		'head' : "Problems",
		'ind' : 0,
		'bg' : 'bat.jpg',
		# 'bg' : 'anon1.jpg',
		'h1' : 'Challenges'
	}

	get = requests.GET or None

	lunch['questions'] = []

	obj = open('questions.txt', 'r')
	data = obj.read().strip().split('***')
	obj.close() 

	for i in range(len(data)):
		l = data[i].split('~~')
		l.append(i)
		lunch['questions'].append(Question(l))
	if get == None:
		lunch['flag'] = True
	elif get['id']:
		lunch['pset'] = lunch['questions'][int(get['id'])]
		print get['id']

	return render(requests, 'pset.html', lunch)

def upload(request):
    if request.method == 'POST' and request.FILES['myfile']:
        myfile = request.FILES['myfile']
        team_name = request.POST['team_name']
        fs = FileSystemStorage()
        filename = fs.save('uploadedFiles/' + team_name + '/' + myfile.name, myfile)
        uploaded_file_url = fs.url(filename)
        return render(request, 'file.html', {
            'uploaded_file_url': uploaded_file_url,
            'bg' : 'bat.jpg',
            'head' : 'Upload',
            'h1' : 'Upload your files',
        })
    return render(request, 'file.html', {'bg' : 'bat.jpg', 'head' : 'Upload','h1' : 'Upload your files',})