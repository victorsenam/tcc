#!/usr/bin/python3
import os
import difflib
import subprocess
import sys

def parseFileName (filename):
	parts = filename.split('.')
	if len(parts) != 3 or parts[1] == "Trivial" or parts[2] != "cpp":
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

		for test in tests:
			test_file = open(root + "/tests/" + test, 'r')
			sys.stdout.write(test + " Running solution...")
			sys.stdout.flush()
			example_out = subprocess.check_output(root + "/" + example_name + ".out", shell=True, stdin=test_file, timeout=2)

			test_file = open(root + "/tests/" + test, 'r')
			sys.stdout.write("\r" + test + " Running trivial...                      ")
			sys.stdout.flush()
			trivial_out = subprocess.check_output(root + "/" + trivial_name + ".out", shell=True, stdin=test_file, timeout=10)
			
			if example_out == trivial_out:
				sys.stdout.write("\r" + test + " \33[0;32;40mOK\33[m...                      \n")
			else:
				sys.stdout.write("\r" + test + " \33[0;30;41mFAIL\33[m(found " + str(example_out) + " expected " + str(trivial_out) + ")\n")
			sys.stdout.flush()

