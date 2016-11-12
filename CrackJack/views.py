from django.shortcuts import render
from django.conf import settings
import random
import os
from django.core.files.storage import FileSystemStorage
from django.views.static import serve

IMAGES = ['super.jpg', 'hq.jpg', 'bg.jpg', 'jd.jpg']

def down(requests):
	filepath = '/static/files/file.txt'
	return serve(requests, os.path.basename(filepath), os.path.dirname(filepath))

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
		'h1' : 'Challenges',
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
	obj = open('key_list.txt', 'r')
	key_data = obj.read().strip().split('\n')
	obj.close()

	key_dict = {}
	for key in key_data:
		key_dict[key.split('~~')[0].strip()] = key.split('~~')[1].strip()

	# print key_dict

	if request.method == 'POST' and 'myfile' in request.FILES.keys():
		myfile = request.FILES['myfile']
		team_name = request.POST['team_name']
		team_pass = request.POST['team_pass']
		# print (team_name, team_pass)
		if team_name in key_dict.keys() and key_dict[team_name] == team_pass and myfile:
			# print "going in!"
			fs = FileSystemStorage()
			filename = fs.save('uploadedFiles/' + team_name + '/' + myfile.name, myfile)
			uploaded_file_url = fs.url(filename)
			msg = 'Uploaded successfully !'
		elif team_name == '' and team_pass =='' and myfile:
			msg = ''
		else:
			uploaded_file_url = False
			msg = "Wrong credentials ! Ask for your team key."
		return render(request, 'file.html', {
		'uploaded_file_url': uploaded_file_url,
		'bg' : 'bat.jpg',
		'head' : 'Upload',
		'h1' : 'Upload your files',
		'msg' : msg
		})
	return render(request, 'file.html', {'bg' : 'bat.jpg', 'head' : 'Upload','h1' : 'Upload your files',})

def downloads(requests):
	lunch = {
		'bg' : 'bat.jpg',
		'head' : 'Downloads',
	}
	return render(requests, 'downloads.html', lunch)