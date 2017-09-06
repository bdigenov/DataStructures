import praw
import sys
import getopt

search = ''
joke_subreddits = ['jokes', 'dadjokes', 'darkhumor', 'cleanjokes']

#sorry shreya
swear_filter = ['fuck', 'shit', 'damn', 'fag'] 


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
			search = a
			


	reddit = praw.Reddit(user_agent='Shreya',
                  client_id='eZG-CeR7tj8LEw',
                  client_secret='95D_3MzDMLiKkxhmmvRhx_Hann0',
                  username='britters46',
                  password='Maggie12')

					   
					 
					 
	for subr in joke_subreddits:
		for submission in reddit.subreddit(subr).top():
			process_submission(submission)
		for submission in reddit.subreddit(subr).hot():
			process_submission(submission)
		
	for subr in joke_subreddits:
		for submission in reddit.subreddit(subr).search(search,sort='top'):
			process_submission(submission)
	

def process_submission(submission):

	if len(submission.selftext) + len(submission.title) > 140:
		return
			
	if submission.over_18:					#no NSFW posts
		return
	
	if not submission.is_self:				#avoids picture posts -- only text aka self posts
		return
	
	normal_title = submission.title.lower()
	normal_text = submission.selftext.lower()
	
	for swears in swear_filter:				#keeps swear words out of the joke book -- its for the kids
		if swears in normal_title:
			return
		if swears in normal_text:
			return
			
	
	if search in normal_title:
		print(submission.title)
		print(submission.selftext)
		sys.exit()
	if search in normal_text:
		print(submission.title)
		print(submission.selftext)
		sys.exit()
	
def usage():
	print 'Usage: mybot.py [-h usage -s search]'

	print 'Options:'

	print '    -h usage    prints help information'
	print '    -s search   what term you would like to search for'
	print '                a joke with'
	sys.exit()

if __name__ == '__main__':
	main()