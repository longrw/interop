/** Unit tests for enum parsing
 *
 *  @file
 *  @date  4/27/16
 *  @version 1.0
 *  @copyright GNU Public License.
 */
#include <gtest/gtest.h>
#include "interop/logic/utils/enums.h"
#include "interop/logic/utils/metric_type_ext.h"


using namespace illumina::interop;


TEST(enum_parsing_test, parse_metric_type)
{
    EXPECT_EQ(constants::enumeration<constants::metric_type>::parse("Intensity"), constants::Intensity);
    EXPECT_EQ(constants::enumeration<constants::metric_type>::parse("FWHM"), constants::FWHM);
    EXPECT_EQ(constants::enumeration<constants::metric_type>::parse("Gobble"), constants::UnknownMetricType);
}

TEST(enum_parsing_test, metric_type_to_string)
{
    EXPECT_EQ(constants::enumeration<constants::metric_type>::to_key(constants::Intensity), std::string("Intensity"));
}

TEST(enum_parsing_test, metric_type_to_group)
{
    EXPECT_EQ(logic::utils::to_group(constants::Intensity), constants::Extraction);
}
