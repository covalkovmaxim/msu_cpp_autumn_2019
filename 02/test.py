import subprocess
def check(expr,result):
    process = subprocess.Popen('./myalloc '+expr, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    out = process.stdout.readlines()
    #print(out)
    if out[0].decode('ascii') !=result:
            print('{0}!={2},got {1} =>  Wrond Answer'.format(expr,result,out[0].decode('ascii')))
    else:
            print('{0}=={2},got {1} => Accepted'.format(expr,result,out[0].decode('ascii')))
check('2 2 2' ,'2 nullptr ')
check('100 10 10 10' ,'10 10 10 ')
check('2 ' ,'Empty input')
check('2 2 wew' ,'2 Invalid input')
check('1000 1001' ,'nullptr ')
check('100 50 51' ,'50 nullptr ')
check('100 100 -1 100' ,'100 100 ')
check('100 20 15 30 20 -1 50 50 -1 100' ,'20 15 30 20 50 50 100 ')
