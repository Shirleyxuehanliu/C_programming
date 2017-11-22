import sqlite3

conn=sqlite3.connect('sfu_refranking.sqlite')
cur=conn.cursor()
cur.execute('SELECT id,newrank FROM Host')
#This returns a list of tuples representing (id, rank)
old_rank=cur.fetchall()
#Build a dictionary to store the previous urls and their corresponding ranking
previous_rank=dict()
previous_rank_dup=dict()
next_rank=dict()
host=list()
for item in old_rank:
    id=item[0]
    rank=item[1]
    previous_rank[id]=rank
    next_rank[id]=0
    host.append(id)

while True:
    for node in host:
#get all the node that the host node is pointing to
        cur.execute('SELECT link_id FROM Links WHERE host_id=?',(node,))
        linked_id=cur.fetchall()
        link_id=list()
        for item in linked_id:
            link_id.append(item[0])
      #  print(type(linked_id))
#Weight of each path
        try:
            weight=previous_rank[node]/len(link_id)
            print('weight', weight)
        except:
            pass
        for m in link_id:
            next_rank[m]=next_rank[m]+weight
    
#There are pages pointing to nowhere, the total weight became smaller if we don't count them,
#the solution is to get the total weight difference and distribute the diff to every page
    old_total=0
    for i in previous_rank.items():
        old_total=old_total+i[1]
    new_total=0
    for i in next_rank.items():
        new_total=new_total+i[1]
    bias=(old_total-new_total)/len(previous_rank.items())
    assert bias >= 0, "bias is {}".format(bias)
    for i in next_rank.keys():
        next_rank[i]=next_rank[i]+bias

#Check the claus of the rank distribution
    totaldiff=0       
    for node in previous_rank.keys():
        old_weight=previous_rank[node]
        next_weight=next_rank[node]
        diff=abs(old_weight-next_weight)
        totaldiff=totaldiff+diff
        previous_rank[node]=next_rank[node]
        next_rank[node]=0
    evap=totaldiff/len(previous_rank.items())
    print('Distribution clause:',evap)
    if evap<0.001:
        break
cur.execute('UPDATE Host SET oldrank=newrank')
for (id,old_rank) in previous_rank.items():
    cur.execute('UPDATE Host SET newrank=? WHERE id=?',(old_rank,id))    
conn.commit()
cur.close()


        

