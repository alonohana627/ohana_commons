project('ohana_commons', 'c',
  version : '0.1.0',
  default_options : ['c_std=c11']
)

inc = include_directories('include')

srcs = files(
  'src/return_five.c'
)

libacommons = library('ohana_commons',
  srcs,
  include_directories : inc,
  install : false
)

libacommons_dep = declare_dependency(
  include_directories : inc,
  link_with : libacommons
)

subdir('tests')
