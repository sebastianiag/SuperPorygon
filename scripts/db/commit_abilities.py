import sqlite3


abilities = open('list_of_abilities.txt', 'r')
id = 0
conn = sqlite3.connect("pokemondb")
cur = conn.cursor()
cur.execute("CREATE TABLE ability(id integer primary key, name text, effect_description text)")
for ability in abilities:
    values = ability.split(" ")
    name = values[0]
    try:
        x = int(values[1])
        command = 'INSERT INTO ability VALUES (%d, "%s", "%s")' % (id, name, " ".join(values[2:-1]))
        id += 1
        cur.execute(command)
    except:
        name = name +" "+ values[1]
        command = 'INSERT INTO ability VALUES (%d, "%s", "%s")' % (id, name, " ".join(values[3:-1]))
        id += 1
        cur.execute(command)

conn.commit()
conn.close()
    
