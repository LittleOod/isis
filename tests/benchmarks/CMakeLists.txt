############################################################
# The ISIS project
# 
# Main CMake configuration file of the ISIS DataStorage tests.
#
# Author: Thomas Proeger <thomasproeger@googlemail.com>
# Date: Tue, 28 Jun 2011 18:46:55 +0200
# 
############################################################

############################################################
# configure targets
############################################################

add_executable( imageStresstest imageStresstest.cpp )
add_executable( typePtrStresstest typePtrStresstest.cpp )

target_link_libraries( imageStresstest ${Boost_LIBRARIES} isis_core ${ISIS_LIB_DEPENDS} )
target_link_libraries( typePtrStresstest ${Boost_LIBRARIES} isis_core ${ISIS_LIB_DEPENDS} )

############################################################
# add unit test targets
############################################################

# benchmarks are no default unit test targets
# add_test(NAME imageStresstest COMMAND imageStresstest)
# add_test(NAME typePtrStresstest COMMAND typePtrStresstest)

