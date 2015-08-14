#-*-encoding: utf-8 -*-
from argparse import ArgumentParser
import BeautifulSoup
import requests

parser = ArgumentParser()
parser.add_argument('--download_abilities', action='store_true', help="download the individual ability html")
parser.add_argument('--organize', action='store_true', help="organize ability files")

args = parser.parse_args()
if args.download_abilities:
    try:
        source_list = open("ability.html", 'r').read()
        soup = BeautifulSoup.BeautifulSoup(source_list)
        table = soup.find('table', attrs={'id':'abilities'})
        rows = table.findAll('tr')[1:]
        for row in rows:
            name = (row.find('td')).text
            link = "http://pokemondb.net" + (row.find('a', attrs={'class':'ent-name'}))['href']
            print "downloading link for %s in %s" % (name, link)
            r = requests.get(link)
            attack_file = open("ability/%s.html" % name, 'wb')
            attack_file.write((r.text).encode('utf-8'))
            attack_file.close()
    except:
        print "No connection or page not found"
 
if args.organize:
    import os
    destination_file = open("ability_description.html", 'r').read()
    soup = BeautifulSoup.BeautifulSoup(destination_file)
    gen = os.walk("./ability/")
    for (dirpath, _, filenames) in gen:
        for f in filenames:
            try:
                ability = open("ability/"+f, 'r').read()
                print "writing shit for %s" %f
                ability_soup = BeautifulSoup.BeautifulSoup(ability)
                soup.body.append("<b>###################################################################</b>")
                soup.body.append(ability_soup.find('article', attrs={'class':'main-content grid-wrapper'}))
            except:
                continue
    
    destination_fil = open("ability_description.html", 'wb').write(soup.prettify())

print "Finished..."
