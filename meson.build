project('ohana_commons', 'c',
  version : '0.1.0',
  default_options : ['c_std=c11']
)

inc = include_directories('include')

libs = files(
  'lib/dynamic_str.c',
  'lib/find_next_power_of_two.c'
)

libacommons = library('ohana_commons',
  libs,
  include_directories : inc,
  install : false
)

libacommons_dep = declare_dependency(
  include_directories : inc,
  link_with : libacommons
)

subdir('tests')
