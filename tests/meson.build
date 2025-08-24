# <test_name> = executable('<test_exe_name>',
#   '<c file of the test>.c',
#   dependencies : [athread_dep]
# )
# test('test name in the terminal', <test_name>)

test_find_next_power_of_two = executable('test_find_next_power_of_two',
  'test_find_next_power_of_two.c',
  dependencies : [libacommons_dep]
)
test('test_find_next_power_of_two', test_find_next_power_of_two)

# dynamic str tests
subdir('dynamic_str')
