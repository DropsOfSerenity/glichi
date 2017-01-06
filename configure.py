import sys
import os
import platform
import ninja_syntax

def walk_src(n, path, objdir):
  obj = []
  for (dirpath, dirnames, filenames) in os.walk(path):
    for f in filenames:
      _, ext = os.path.splitext(f)
      if ext == '.c':
        s = os.path.relpath(os.path.join(dirpath, f), path)
        o = s.replace('.c', '.o')
        obj += n.build(os.path.join(objdir, o), 'cxx', os.path.join(path, s))
  n.newline()
  return obj

def main():
	builddir = 'build'
	target = 'glichi.a'
	srcdir = 'src'
	demodir = 'demo'
	demobuilddir = 'demobuild'
	objdir = builddir + 'obj'
	cflags = '-Wall -Wextra -Werror -g -Ideps/include -Isrc'
	# TODO(justin): break into debug and production builds (console is not needed for prod)
	ldflags = '-Ldeps/lib -lglfw3 -lopengl32 -lglew32 -mwindows -mconsole'

	BUILD_FILENAME = 'build.ninja'
	buildfile = open(BUILD_FILENAME, 'w')
	n = ninja_syntax.Writer(buildfile)

	n.variable('cflags', cflags)
	n.variable('ldflags', ldflags)
	n.rule('cxx',
		command='gcc -MMD -MF $out.d $cflags -c $in -o $out',
	    depfile='$out.d',
	    description='CXX $out')
	n.rule('ar',
	    command='ar rcs $out $in')
	n.rule('link',
	    command='gcc $in $libs $ldflags -o $out',
	    description='LINK $out')
	n.rule('cp',
	    command='cp $in $out',
	    description='COPY $in $out')

	obj = walk_src(n, srcdir, objdir)
	targets = []
	library = n.build('build/' + target, 'ar', obj)
	targets += library
	n.newline()

	obj = walk_src(n, demodir, objdir)
	targets += n.build(demobuilddir + '/example', 'link', obj + library)
	n.newline()

	targets += n.build(os.path.join(demobuilddir, 'glfw3.dll'), 'cp', os.path.join('deps', 'lib', 'glfw3.dll'))
	targets += n.build(os.path.join(demobuilddir, 'glew32.dll'), 'cp', os.path.join('deps', 'lib', 'glew32.dll'))

	n.build('all', 'phony', targets)
	n.default('all')

if __name__ == '__main__':
	main()