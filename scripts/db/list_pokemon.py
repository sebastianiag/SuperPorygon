import requests
import sqlite3
import BeautifulSoup
import time

conn = sqlite3.connect("pokemondb")
cur = conn.cursor()

pkmn_list = cur.execute("SELECT name FROM pokemon")

base_url = "http://pokemondb.net/pokedex/"
headers = {"user-agent": "Mozilla/5.0 (X11; Linux i586; rv:31.0) Gecko/20100101 Firefox/31.0"}

for pair in pkmn_list:
    url = base_url+pair[0]
    print "getting %s from %s." % (pair[0], url)

    try:
        req = requests.get(url, headers=headers)
    except:
        print "error in requesting %s" % (url)
        continue

    pkmn_file = open("./pokedex/%s.html" % pair[0], 'wb')
    soup = BeautifulSoup.BeautifulSoup(req.text)
    pkmn_file.write(soup.prettify())
    pkmn_file.close()
    time.sleep(1)
