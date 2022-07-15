import json
import pymysql
    
with open("D://temp.json", encoding='utf-8') as file:
    mysql_conn = pymysql.connect(host='192.168.0.6', user='dev', password='pwd0000', db='OnlineSearch', charset='utf8')
    mysql_cur = mysql_conn.cursor()

    root = json.load(file)
    records = root['records']

    query = 'INSERT INTO poiTable(poiName, old_addr, new_addr, phone) VALUES (%s, %s, %s, %s)'
    for record in records:
        values = (str(record['관광지명']), str(record['소재지지번주소']), str(record['소재지도로명주소']), str(record['관리기관전화번호']))
        mysql_cur.execute(query, values)
    mysql_conn.commit()