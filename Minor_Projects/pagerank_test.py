import sqlite3

conn=sqlite3.connect('sfu_refranking1.sqlite')
cur=conn.cursor()
cur.execute('SELECT id,newrank FROM Host')
#This returns a list of tuples representing (id, rank)
old_rank=cur.fetchall()
#Build a dictionary to store the previous urls and their corresponding ranking
previous_rank=dict()
next_rank=dict()
host=list()
for item in old_rank:
    id=item[0]
    rank=item[1]
    previous_rank[id]=rank
    next_rank[id]=0
    host.append(id)
print ('previous_rank is:', previous_rank)
print ('next_rank is:', next_rank)
num=0
while True:
    for node in host:
        count=0
#get all the node that the host node is pointing to
        cur.execute('SELECT link_id FROM Links WHERE host_id=?',(node,))
        linked_id=cur.fetchall()
        print ('linked_id is:', linked_id)
        link_id=list()
        for item in linked_id:
            link_id.append(item[0])
        print ('link_id is:', link_id)   
      #  print(type(linked_id))
#Weight of each path
        try:
            weight=previous_rank[node]/len(link_id)
            print('weight', weight)
        except:
            print('This page points to nowhere!')
        for m in link_id:
            next_rank[m]=next_rank[m]+weight
        count=count+1
        print('==================count',count,'================')
        print ('previous_rank is:', previous_rank)
        print ('next_rank is:', next_rank)
        
    old_total=0
    for i in previous_rank.items():
        old_total=old_total+i[1]
    new_total=0
    for i in next_rank.items():
        new_total=new_total+i[1]
    print('old_total:',old_total)
    print('new_total:',new_total)
    bias=(old_total-new_total)/len(previous_rank.items())
    assert bias >= 0, "bias is {}".format(bias)
    for i in next_rank.keys():
        next_rank[i]=next_rank[i]+bias
    print ('previous_rank is:', previous_rank)
    print ('next_rank is:', next_rank)

    totaldiff=0       
    for node in previous_rank.keys():
        old_weight=previous_rank[node]
        next_weight=next_rank[node]
        diff=abs(old_weight-next_weight)
        totaldiff=totaldiff+diff
        previous_rank[node]=next_rank[node]
        next_rank[node]=0
    evap=totaldiff/len(previous_rank.items())
    print('difference is :',evap)
    print ('previous_rank is:', previous_rank)
    print ('next_rank is:', next_rank)
    print('+++++++++Finish one time of iteration++++++')
    num=num+1
#Check the claus of the rank distribution
    if num==2:
        break