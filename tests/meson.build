# <test_name> = executable('<test_exe_name>',
#   '<c file of the test>.c',
#   dependencies : [athread_dep]
# )
# test('test name in the terminal', <test_name>)

test_return_five = executable('test_return_five',
  'test_return_five.c',
  dependencies : [libacommons_dep]
)
test('test_return_five', test_return_five)
