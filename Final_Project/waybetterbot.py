
#Code created and written by Collin Klenke, Brittany DiGenova, and Maggie Thomann ##################|
#December 5th, 2016#################################################################################|#
#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~#~*~|#
#sorry shreya	####################################################################################|##
swear_filter = ['fuck', 'shit', 'damn', 'fag', 'bitch', 'cunt', 'ass', 'pussy', 'cock', 'dick'] ####|###
#sorry shreya, its for a good cause	################################################################|#####
#How can I protect these keeeeeeeds  ###############################################################|########
####################################################################################################|#############

import praw
import sys
import getopt


search = ''
joke_subreddits = ['jokes', 'dadjokes', 'darkhumor', 'cleanjokes']

def main():
	
	try:
		opts, args = getopt.getopt(sys.argv[1:], 'hs:')
	except getopt.GetoptError as err:
		print str(err)
		usage()
		sys.exit(2)
	
	for o, a in opts:
		if o == '-h':
			usage()
			sys.exit()
		elif o == '-s':
			global search
			search = ' '.join(sys.argv[2:]).lower()		#allows for more than one word phrases
			
			


	reddit = praw.Reddit(user_agent='Shreya\'s Bot',
					   client_id='2PUOnje2y1kNBA',
					   client_secret='L2vSkW0V6Wvf7eOe53bt3nDeN0s',
					   username='Shreyas_bot',
					   password='maggie12')				#Reddit bot to scrape information
					   
					 
					 
	for subr in joke_subreddits:						#increment through the subreddits
		for submission in reddit.subreddit(subr).top(): #increment through the posts in top
			process_submission(submission)
		for submission in reddit.subreddit(subr).hot(): #increment through the posts in hot
			process_submission(submission)
		
	for subr in joke_subreddits:
		for submission in reddit.subreddit(subr).search(search,sort='top'): #joke finder failsafe, uses reddit's search function
			process_submission(submission)									# while we could have just used this, it wasn't as fun 
	

def process_submission(submission):

	if len(submission.selftext) + len(submission.title) > 140:				#nobody wants to sit and read a long joke -- keep em short and sweet
		return 
			
	if submission.over_18:					#no NSFW posts
		return
	
	if not submission.is_self:				#avoids picture posts -- only text aka self posts
		return
	
	normal_title = submission.title.lower()
	normal_text = submission.selftext.lower()
	
	for swears in swear_filter:				#keeps swear words out of the joke book -- its for the kids
		if swears in normal_title:			#if you have have have to see swear_filter, look at line 6, but its not pretty
			return							
		if swears in normal_text:
			return
			
	
	if search in normal_title:				#reddit text posts have a "title" and a "text" so we search through both for our keyword
		print(submission.title)				# if the keyword is found, print out the title and text and then end the script, as we only need one joke
		print(submission.selftext)
		sys.exit()
	if search in normal_text:
		print(submission.title)
		print(submission.selftext)
		sys.exit()
	
def usage():
	print 'Usage: waybetterbot.py [-h usage -s search]'

	print 'Options:'

	print '    -h usage    prints help information'
	print '    -s search   what term you would like to search for'
	print '                a joke with'
	sys.exit()

if __name__ == '__main__':
	main()
	
