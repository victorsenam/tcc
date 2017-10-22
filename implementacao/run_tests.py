#!/usr/bin/python3
import os
import difflib
import subprocess
import sys

root = "./exemplos"
test_folder_name = "tests"

def makeExample(path):
	os.system("make " + path)

def runCase(path, example, case, timeout=3):
	sys.stdout.write(case + "...")
	sys.stdout.flush()
	case_file = open(os.path.join(path, test_folder_name, case))
	return subprocess.check_output(os.path.join(path, example), shell=True, stdin=case_file, timeout=timeout)
	
for test in map(os.path.basename, filter(os.DirEntry.is_dir,os.scandir(root))):
	print("== \33[0;32;40m" + test + "\33[m ==")

	if (not os.path.isdir(os.path.join(root, test, test_folder_name))):
		print("= \33[0;33;40mNo tests!\33[m =")
	
	trivial_path = os.path.join(root, test, test + ".Trivial")
	if (not os.path.exists(trivial_path + ".cpp")):
		print("= \33[0;33;40mNo trivial!\33[m =")
	

	cases = list(map(os.path.basename, filter(lambda x : x.name.endswith('.in'), os.scandir(os.path.join(root, test, test_folder_name)))))
	print("= Generating trivial input =")
	makeExample(trivial_path + ".out")
	expected = {}
	for case in cases:
		expected[case] = runCase(os.path.join(root, test), test + ".Trivial.out", case, 10)
		sys.stdout.write(" Done\n")

	examples = filter(lambda x : x.startswith(test + ".") and x.endswith(".cpp") and x != test + ".Trivial.cpp", map(os.path.basename, os.scandir(os.path.join(root, test))))
	for example in examples:
		example = example.rstrip(".cpp")
		example_path = os.path.join(root, test, example)

		print("= Running \33[0;32;40m" + example + "\33[m =")
		makeExample(example_path + ".out")

		for case in cases:
			output = runCase(os.path.join(root, test), ".".join([example,"out"]), case)
			if output == expected[case]:
				print(" \33[0;32;40mOK\33[m | " + str(output))
			else:
				print(" \33[0;30;41mFAIL\33[m")
				print("Expected:")
				print(str(expected[case]))
				print("Found:")
				print(str(output))
