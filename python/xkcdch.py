#!/usr/bin/env python
###########################
# xkcdch.py ###############
# Check for a new xkcd. ###
# Nice to run at startup. #
# ckjbgames 2017 ##########
###########################
import os, urllib2, Tkinter, tkMessageBox
from bs4 import BeautifulSoup
def xkcdt():
    """
    Return the title of the
    most recent xkcd, taken from
    the wesite's source code.
    """
    page=BeautifulSoup(urllib2.urlopen('https://xkcd.com'),'lxml')
    return page.title.string
if __name__ == '__main__':
    if os.path.exists('./.xkcd'):
        if open('./.xkcd','r').read() == xkcdt():
            with open('./.xkcd','w') as f:
                f.write(xkcdt())
                f.close()
    else:
        with open('./.xkcd','w+') as f:
            f.write(xkcdt())
            f.close()
