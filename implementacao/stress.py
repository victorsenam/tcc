#!/usr/bin/python3
import os
import difflib
import subprocess
import sys

which = input()

def parseFileName (filename):
	parts = filename.split('.')
	if len(parts) != 3 or parts[1] == "Trivial" or parts[2] != "cpp" or filename != which:
		return False
	return parts
	
for root, dirs, files in os.walk("."):
	if ("tests" not in dirs):
		continue
	tests = list(filter(lambda x : x.endswith('.in'), os.listdir(root + '/tests')))

	examples = filter(lambda x : x != False, map(parseFileName, files))
	for example in examples:
		example_name = example[0] + '.' + example[1]
		print("\33[0;32;40m" + example_name + "\33[m")

		trivial_name = example[0] + '.Trivial'
		if (trivial_name + '.cpp' not in files):
			print("Trivial not found!")
			continue

		os.system("make " + root + "/" + trivial_name + ".out")
		os.system("make " + root + "/" + example_name + ".out")

		test = 0
		while True:
			test += 1
			sys.stdout.write("\r" + str(test) + " Generating test...                                  ")
			sys.stdout.flush()
			case = subprocess.check_output(root + "/tests/gen.py", input=b'100\n', timeout=1)

			sys.stdout.write("\r" + str(test) + " Running solution...                                  ")
			sys.stdout.flush()
			example_out = subprocess.check_output(root + "/" + example_name + ".out", shell=True, input=case, timeout=2)

			sys.stdout.write("\r" + str(test) + " Running trivial...                                         ")
			sys.stdout.flush()
			trivial_out = subprocess.check_output(root + "/" + trivial_name + ".out", shell=True, input=case, timeout=3)
			
			if example_out == trivial_out:
				sys.stdout.write("\r" + str(test) + " \33[0;32;40mOK\33[m... " + str(example_out) + "                     ")
				sys.stdout.flush()
			else:
				sys.stdout.write("\r" + str(test) + " \33[0;30;41mFAIL\33[m(found " + str(example_out) + " expected " + str(trivial_out) + ")\n")
				sys.stdout.flush()
				print(case)
				break

