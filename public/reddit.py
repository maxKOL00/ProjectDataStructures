import praw  # Python Reddit API Wrapper
from nltk.tokenize import word_tokenize  # tool to get each word in a sentence/phrase
import os, emoji, os.path, re # os exectues .exe file, emoji handles titles with emojis

reddit = praw.Reddit(client_id='Tu5oWsGc7cnafw',
                     client_secret='hjRwgAylwvkcGjxJWyPAT-eYIhI',
                     username='DankulousMemeLord',
                     password='Blue12House$',
                     user_agent='memes')  # logging into reddit

print('Logged into Reddit')
subreddit = reddit.subreddit('Memes_Of_The_Dank')  # specify which subreddit to read from

hot = subreddit.hot(limit=7)  # get memes from new, limit shows hwo many 

save_path = 'C:/Users/Max/OneDrive/ds-project/public/'#path to text file

completeName = os.path.join(save_path, "memes.txt")#put file in public. server can find it only there
file = open(completeName, "w")#open the file and write to it


def repost_check(comment):
    for i in word_tokenize(comment):#puts comments into an array
        word = i.lower()#make everything lowercase
        #catches reeee with any oamount of ees
        if word == 're' or word == 'ree' or word == 'reee' or re.search("^reee.*e$", word):
            print('flagged word: ', word)
            return True
        if word == 'repost':
            print('flagged word: ', word)
            return True

    return False

def extract_emojis(str):#since emojis can't be written propely to the file
    return ''.join(c for c in str if c in emoji.UNICODE_EMOJI)

for submission in hot:
    if not submission.stickied:#posts that always come up first in a subreddit
        title = submission.title
        if not extract_emojis(title): # if title only contained emojis
                print(title)
        else:
            print("emoji")#change the title to emoji
        url = submission.url
        upVotes = submission.ups
        time = submission.created_utc
        comments = submission.comments.list()
        repost = False
        print('Checking comments for signs of a repost...')
        for comment in comments:
            repost = repost_check(comment.body)#check the comments for signs of repost
            if repost:
                print('REPOST')
                break

        if repost is None:#incase the comments can't be parsed to to unknown character
            print('Error reading boolean', '\n', '\n')
        elif not repost:
            print('Writing to file...', '\n', '\n')
            if not extract_emojis(title): # if title only contained emojis
                file.write(title)
            else:
                file.write("emoji")
            file.write('\n')
            file.write(url)
            file.write('\n')
            file.write(str(upVotes))
            file.write('\n')
            file.write(str(time))
            file.write('\n')
        else:
            print('Do not write post (repost)', '\n')

file.close()#close the memes.txt file

os.system("C:/Users/Max/OneDrive/ds-project/public/sort.exe")#sorts the memes and writes the html file
