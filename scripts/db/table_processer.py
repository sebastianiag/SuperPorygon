import BeautifulSoup
import sqlite3

def to_int(s):
    try:
        x= int(s)
        return s
    except:
        return "NULL"

conn = sqlite3.connect('pokemondb')
cur = conn.cursor()

cur.execute("CREATE TABLE attack(id integer primary key, name text, type text, category text, power integer, acc integer, pp integer, tm integer, effect text, effect_probability integer)")
f = open("attacks.html", 'r').read()
soup = BeautifulSoup.BeautifulSoup(f);
table = soup.find('table', attrs={"id": "moves"})
i=1
rows = table.findAll('tr')
for row in rows[1:]:
    columns = map(lambda x: x.text, row.findAll('td'))
    print columns
    command = 'INSERT INTO attack VALUES ("%d", "%s", "%s", "%s", %s, %s, %s, %s, "%s", %s)' % (i, columns[0], columns[1], columns[2], to_int(columns[3]), to_int(columns[4]), to_int(columns[5]), to_int(columns[6]), columns[7], to_int(columns[8]))
    i += 1
    cur.execute(command)

conn.commit()
conn.close()
    

