#Uses PRAW wrapper to implement the reddit bot Shreya 
import praw
import requests

#declare bot 
bot = praw.Reddit(user_agent='Shreya',
                  client_id='eZG-CeR7tj8LEw',
                  client_secret='95D_3MzDMLiKkxhmmvRhx_Hann0',
                  username='britters46',
                  password='Maggie12')

r = requests.get("http://www.reddit.com/r/funny/hot")

print r.content