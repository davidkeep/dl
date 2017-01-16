# Extends Sublime Text autocompletion to find matches in all open
# files. By default, Sublime only considers words from the current file.

import sublime_plugin
import sublime
import re
import time
from os.path import basename
from subprocess import Popen, PIPE
import _thread

class dlAutocomplete(sublime_plugin.EventListener):
	completions = []

	running = False

	def executeQuery(self, view, locations):
	
		self.completions = [
			["fn\tIdentifier fn(...) {}", "${1:Name} fn($2) {\n$0\n}"],
		   	["struct\tIdentifier struct {}", "${1:Name} struct {\n$0\n}"],
			["for\tfor from..to", "for ${1:from} .. ${2:to} {\n\t$0\n}"],
			["if\tif ... ", "if $1 {\n\t$0\n}"]
		]

		file = view.file_name()
		at = locations[0]
		rc = view.rowcol(at)
	
		start = locations[0]
		end = locations[0]


		cmd = 'completionsAt'

		while start > 0:
			if view.substr(start) == '.':
				cmd = 'completionsDot'
				self.completions = []
				break
			if view.substr(start) == ' ':
				start = locations[0]
				break
			if view.substr(start) == '\t':
				start = locations[0]
				break
			if view.substr(start) == '(':
				start = locations[0]
				break

			start = start - 1
			
		command = cmd + " '" + file + "' " + str(rc[0]+1) + ' ' + str(rc[1]) + '\n'
		print(command)

		data = view.substr(sublime.Region(0, start))
		data += view.substr(sublime.Region(end, view.size()))


		proc = Popen(['/Users/David/Desktop/dl/tools/dl/release/dl', '/Users/David/Desktop/dl/Min/Main.dl','-b', '-map',file, data, command], stdout=PIPE, stderr=PIPE, stdin=PIPE, shell=False)


		# print(body)
		# print(at)
		# print(lookup)

		while True:
			out = proc.stdout.readline().decode('UTF-8').rstrip('\n')
			if not out:
				break

			print(out)
			if out.startswith('completion:'):
				self.completions.append(out[11:].split(";"))

		while True:
			out = proc.stderr.readline().decode('UTF-8').rstrip('\n')
			if not out:
				break
				
			print(out)

			if out.startswith('completion:'):
				self.completions.append(out[11:].split(";"))

		out, err = proc.communicate()
		exitcode = proc.returncode
		self.ShowPopup(view)
		self.running = False


	def on_query_completions(self, view, prefix, locations):
		print('Query: ', prefix)

		if not self.running:
			self.running = True
			_thread.start_new_thread(self.executeQuery, (view, locations))

		return (
			self.completions, sublime.INHIBIT_WORD_COMPLETIONS | sublime.INHIBIT_EXPLICIT_COMPLETIONS
		)
	def ShowPopup(self, view):
		view.run_command('hide_auto_complete')
		view.run_command('auto_complete', 
		{
			'disable_auto_insert': True,
			'api_completions_only': False,
			'next_competion_if_showing': False}
		)
	
