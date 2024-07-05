import os
import sys

'''
TODO: Fix running with list directiories
'''

output = './tests'
source = f'/mnt/c/Users/pamor/Downloads/{sys.argv[1].split(".")[0]}'

os.system(f'gcc {sys.argv[1]} -o {output}/prog -lm')

for filename in os.listdir(f'{source}/input'):
    os.system(f'{output}/prog < {source}/input/{filename} > {output}/{filename}')
    os.system(f'diff {source}/output/{filename} {output}/{filename} -u --color')
