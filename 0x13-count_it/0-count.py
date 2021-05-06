""" Contains the count_words function. """
import requests
import operator


def count_words(subreddit, word_list, after=None, keyword=None):
    """ Prints a sorted count of given keywords from the titles of hot articles on a subreddit. """
    if after is None:
        hot = requests.get('https://api.reddit.com/r/{}/hot'.format(subreddit),
                           headers={'User-Agent': 'madmansilver'},
                           allow_redirects=False).json()
    else:
        hot = requests.get('https://api.reddit.com/r/{}/hot?after={}\
'.format(subreddit, after),
                           headers={'User-Agent': 'madmansilver'},
                           allow_redirects=False).json()

    if 'data' not in hot:
        return None

    if keyword is not None:
        count = 0
        for post in hot.get('data').get('children'):
            if keyword.lower() in post.get('data').get('title').lower():
                for word in post.get('data').get('title').split():
                    if word.lower() == keyword.lower():
                        count += 1

        after = hot.get('data').get('after')

    if after is not None:
        return count_words(subreddit, None, after) + count
    if word_list is None and after is None:
        return count

    res = {}
    for word in word_list:
        res[word] = count_words(subreddit, None, None, word)

    for item in sorted(res.items(), key=operator.itemgetter(1), reverse=True):
        print('{}: {}'.format(item[0], item[1]))