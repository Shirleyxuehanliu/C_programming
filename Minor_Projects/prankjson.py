import sqlite3

conn=sqlite3.connect('sfu_refranking.sqlite')
cur=conn.cursor()

cur.execute('''SELECT COUNT(host_id) AS inbound,id,newrank,url_name
FROM Host
JOIN Links ON Links.link_id=Host.id
GROUP BY id ORDER BY id,inbound''')
#create a js file
fhand=open('rank.js','w')
nodes=list()
maxrank=None
minrank=None
#calculate the max and min pagerank in order to do normolization
for row in cur:
    nodes.append(row[1])
    rank=row[2]
    if maxrank is None or maxrank<rank: maxrank=rank
    if minrank is None or minrank>rank: minrank=rank


fhand.write('pagerankJson={"nodes":[\n')
count=0
map=dict()
ranks=dict()
for node in nodes:
    if count>0: fhand.write('\n')
    ranks[node[3]]=node[2]
    rank=node[2]
    map[node[3]]=count
#calculate the weight of the node
    rank_nor=19*(rank-minrank)/(maxrank-minrank)
    fhand.write('{'+'"weight":'+str(node[0])+',"rank":'+str(rank_nor)+',')
    fhand.write('id:'+str(node[1])+',"url":'+node[3]+'},')
    count=count+1
count=0
cur.execute('SELECT host_id, link_id FROM Links')
fhand.write('"links":[\n')
for row in cur:
    if row[0] or row[1] not in nodes: continue
    if count>0: fhand.write('\n')
#calculate the weight of the path between two
    rank=ranks[row[0]]
    srank=19*(rank-minrank)/(maxrank-minrank)
    fhand.write('{'+'"Source":'+str(row[0])+',"Target":'+str(row[1])+',"value":3},')
fhand.write(']};')
    count=count+1
fhand.close()
cur.close()
print("Open force.html in a browser to view the visualization")