""" Contains the count_words function. """
import requests
import operator


def count_words(subreddit, word_list, after=None):
    """ Prints a sorted count of given keywords from the titles of hot articles on a subreddit. """
    if word_list is None:
        print()
        return

    if isinstance(word_list, list):
        word_list = {key: 0 for key in word_list}

    if after is None:
            hot = requests.get('https://api.reddit.com/r/{}/hot'.format(subreddit),
                            headers={'User-Agent': 'madmansilver'},
                            allow_redirects=False).json()
    else:
            hot = requests.get('https://api.reddit.com/r/{}/hot?after={}'.format(subreddit, after),
                            headers={'User-Agent': 'madmansilver'},
                            allow_redirects=False).json()

    if 'data' not in hot:
        for item in sorted(res.items(), key=operator.itemgetter(1), reverse=True):
            if (item[1] != 0):
                print('{}: {}'.format(item[0], item[1]))
        
        return

    for post in hot.get('data').get('children'):
        for key in word_list.keys():
            word_list[key] += post.get('data').get('title').lower().count(key.lower())

    after = hot.get('data').get('after')
    count_words(subreddit, word_list, after)
