#!/usr/bin/env python

#   Author: Sebastian Draxinger
#   Projekt: Krake
#   Status: In Arbeit

import sqlite3
import sys
import cgi
import cgitb

#   GLOBAL VARIABLES
dbname = '/var/www/krakelog.db'

#   DEFINES
COMMANDS_SQLITE3 = {
    "ALLE DATEN" : "SELECT * FROM krake",
    "DATEN IN INTERVAL" : "SELECT * FROM krake WHERE timestamp > datetime('now', '-%s hours')",
}

def main():
    # Pseudo Code
    # Enable CGI and Get Sent Options
    # Print HTML Header
    # Load Data From Database
    # Print HTML Intro with Title etc.
    # Print HTML Body Intro For Temperature
    # Show Tempt Graph
    # Show Temp Stats
    # 
    # Print HTML Intro For Truebung
    # Show Truebung Graph
    # Show Truebung Stats
    # 
    # Print HTML Intro For PH
    # Show PH Graph
    # Show PH Stats


    cgitb.enable()
    
    option = get_option()

    if option is None:
        option = str(100)
    
    records = get_data(option)

    printHTTPHeader()

    if len(records) != 0:
        table_temp = create_table(records, "temperatur")
        table_trueb = create_table(records, "truebung")
        table_ph = create_table(records, "ph")
    else:
        print("No data found")
        return
    
    print("<html>")
    printHTMLHead("Temperatur", table_temp)
    print_graph_script(table_trueb, id="truebung")
    print_graph_script(table_ph, id="ph")
    print("<body>")
    print("<h1>LOGGER</h1>")
    
    # #####################################
    print("<h2>Temperatur</h2>")
    print("<hr>")
    print_time_selector(option)
    show_graph("temperatur")
    show_stats("temperatur")

    print("<h2>Truebung</h2>")
    print("<hr>")
    print_time_selector(option)
    show_graph("truebung", id="truebung")
    show_stats("truebung")

    print("<h2>PH</h2>")
    print("<hr>")
    print_time_selector(option)
    show_graph("ph", id="ph")
    show_stats("ph")

    print("</body>") 
    print("</html>")

    sys.stdout.flush()

def print_graph_script(table, id="chart_div"):
        # google chart snippet
    chart_code="""
    <script type="text/javascript" src="https://www.google.com/jsapi"></script>
    <script type="text/javascript">
      google.load("visualization", "1", {packages:["corechart"]});
      google.setOnLoadCallback(drawChart);
      function drawChart() {
        var data = google.visualization.arrayToDataTable([
          ['Time', 'temperatur'],
%s
        ]);

        var options = {
          title: 'Temperatur'
        };

        var chart = new google.visualization.LineChart(document.getElementById('%s'));
        chart.draw(data, options);
      }
    </script>"""

    print(chart_code % (table, id))

def printHTMLHead(title, table):
    print("<head>")
    print("    <title>")
    print(title)
    print("    </title>")
    
    print_graph_script(table)

    print("</head>")

def show_stats(column, option = 1000):

    col = -1
    if column == "temperatur":
        col = 1
    elif column == "truebung":
        col = 2
    elif column == "ph":
        col = 3
    
    conn = sqlite3.connect(dbname)
    curs = conn.cursor()

    if option is None:
        option = str(24)
    
  

    curs.execute("SELECT timestamp, max(%s) FROM krake WHERE timestamp > datetime('now', '-%s hour') AND timestamp <= datetime('now')" % (column, option))
    rowmax = curs.fetchone()
    rowstrmax = "{0}&nbsp&nbsp&nbsp{1}C".format(str(rowmax[0]), str(rowmax[1]))

    curs.execute("SELECT timestamp, min(%s) FROM krake WHERE timestamp > datetime('now', '-%s hour') AND timestamp <= datetime('now')" % (column, option))
    rowmin = curs.fetchone()
    rowstrmin = "{0}&nbsp&nbsp&nbsp{1}C".format(str(rowmin[0]), str(rowmin[1]))

    curs.execute("SELECT timestamp, avg(%s) FROM krake WHERE timestamp > datetime('now', '-%s hour') AND timestamp <= datetime('now')" % (column, option))
    rowavg = curs.fetchone()
    rowstravg = "{0}&nbsp&nbsp&nbsp{1}C".format(str(rowavg[0]), str(rowavg[1]))

    print("<hr>")

    print("<h2>Minumum %s&nbsp</h2>" % column)
    print(rowstrmin)
    print("<h2>Maximum %s</h2>" % column)
    print(rowstrmax)
    print("<h2>Average %s</h2>" %column)
    print("%.3f" % rowavg[1])

    print("<hr>")

    print("<h2>In the last hour:</h2>")
    print("<table>")
    print("<tr><td><strong>Date/Time</strong></td><td><strong>%s</strong></td></tr>" % column)

    rows = curs.execute("SELECT * FROM krake WHERE timestamp > datetime('new','-1 hour') AND timestamp<=datetime('new')")


    for row in rows:
        rowstr = "<tr><td>{0}&emsp;&emsp;</td><td>{1}C</td></tr>".format(str(row[0]),str(row[col]))
        print(rowstr)
    print("</table>")
    print("<hr>")
    conn.close()

def show_graph(column, id="chart_div"):
    print("<h2>%s Chart</h2>" % column)
    print('<div id="%s" style="width: 900px; height: 500px;"></div>' % id)

def print_time_selector(option):
    print("""<form action="/cgi-bin/krakegui.py" method="POST">
        Show the temperature logs for  
        <select name="timeinterval">""")

    if option is not None:

        if option == "6":
            print("<option value=\"6\" selected=\"selected\">the last 6 hours</option>")
        else:
            print("<option value=\"6\">the last 6 hours</option>")

        if option == "12":
            print("<option value=\"12\" selected=\"selected\">the last 12 hours</option>")
        else:
            print("<option value=\"12\">the last 12 hours</option>")

        if option == "24":
            print("<option value=\"24\" selected=\"selected\">the last 24 hours</option>")
        else:
            print("<option value=\"24\">the last 24 hours</option>")

    else:
        print("""<option value="6">the last 6 hours</option>
            <option value="12">the last 12 hours</option>
            <option value="24" selected="selected">the last 24 hours</option>""")

    print("""        </select>
        <input type="submit" value="Display">
    </form>""")
    

def create_table(rows, col):

    colnum = -1
    if(col == "temperatur"):
        col = 1
    elif(col == "truebung"):
        col = 2
    elif(col == "ph"):
        col = 3
    else:
        return None
    
    chart_table = ""

    for row in rows[:-1]:
        rowstr = "['{0}', {1}],\n".format(str(row[0]), str(row[col]))
        chart_table += rowstr

    return chart_table

def printHTTPHeader():
    print("Content-type: text/html\n\n")

def get_data(interval):

    conn = sqlite3.connect(dbname)
    curs = conn.cursor()

    if interval == None:
        curs.execute(COMMANDS_SQLITE3["ALLE DATEN"])
    else:
        curs.execute(COMMANDS_SQLITE3["DATEN IN INTERVAL"] % interval)

    rows = curs.fetchall()

    conn.close()

    return rows




def get_option():
    form = cgi.FieldStorage()
    if "timeinterval" in form:
        option = form["timeinterval"].value
        return validate_input(option)
    else:
        return 100



def validate_input(option_str):
    # check that the option string represents a number
    if option_str.isalnum():
        # check that the option is within a specific range
        if int(option_str) > 0 and int(option_str) <= 24:
            return option_str
        else:
            return None
    else:
        return None

    
    
    
    

if __name__=="__main__":
    main()


