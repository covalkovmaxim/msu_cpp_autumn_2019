import subprocess
def check(expr,result):
	out=subprocess.run(['./calc',expr],stdout=subprocess.PIPE)
	if out.stdout.decode('ascii') !=result:
		print('{0}!={2},got {1} =>  Wrond Answer'.format(expr,result,out.stdout.decode('ascii')))
	else:
		print('{0}=={2},got {1} => Accepted'.format(expr,result,out.stdout.decode('ascii')))
check('2+2','4')
check('3+3','6')
check('2 + 3 * 4 - -2','16')
check('3+3*3/5-7','-3')
check('1+7/3*3-8/2/2*3+1','2')
check('-1+++++++++2','1')
check('---2----2','0')
check('jerighsdjfkgjdksd','Error')
check('2+2/','Error')
check('3/*3','Error')
check('3/0','Error') 
check('','Error')  	
