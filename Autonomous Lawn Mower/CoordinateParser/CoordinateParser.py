# Usage: python3 CoordinateParser.py [name.waypoints]

import re
import sys

def main() :
  fName = "simple.waypoints"

  with open( fName, 'r' ) as fp:
    lines = fp.read().split( '\n' )

  waypoints = []

  for n in range(1, len(lines)-1):
    coords = lines[n].split('\t')
    newcoord = coords[8] + "\t" + coords[9] + "\n"

    waypoints.append([coords[8], coords[9]])
    #waypoints[n][0] = coords[8]
    #waypoints[n][1] = coords[9]

  fp.close()

  print(waypoints[2][0])

  print('outputted as coords.txt')

#--------------------------------------------------
if ( __name__ == '__main__' ) :
  main()

#--------------------------------------------------
