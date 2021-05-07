#!/usr/bin/python3
""" Contains the count_words function. """
import requests
import operator


def count_words(subreddit, word_list, after=None, dic=None):
    """ Counts keywords from the titles of hot posts on a subreddit. """
    if dic is None:
        word_list = [word.lower() for word in word_list]
        dic = {key: 0 for key in word_list}

    hot = requests.get('https://api.reddit.com/r/{}/hot\
'.format(subreddit) + ('?after={}'.format(after) if after is not None else ''),
                       headers={'User-Agent': 'madmansilver'},
                       allow_redirects=False).json()

    if 'data' not in hot:
        print()
        return

    for post in hot.get('data').get('children'):
        for key in word_list:
            dic[key] += post.get('data').get('title').lower().count(key)

    after = hot.get('data').get('after')

    if after is None:
        for item in sorted(dic.items(), key=operator.itemgetter(1),
                           reverse=True):
            if (item[1] != 0):
                print('{}: {}'.format(item[0], item[1]))
        return

    count_words(subreddit, word_list, after, dic)
