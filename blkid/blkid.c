#include <blkid.h>
#include <libguile.h>

SCM blkid_evaluate_tag_wrapper (SCM name, SCM data)
{
  char *result;
  result = blkid_evaluate_tag(scm_to_locale_string(name), scm_to_locale_string(data), NULL);
  return scm_take_locale_string(result);
}

SCM blkid_evaluate_spec_wrapper (SCM spec)
{
  char *result;
  result = blkid_evaluate_tag(scm_to_locale_string(name), NULL);
  return scm_take_locale_string(result);
}

void init_blkid();
{
  scm_c_define_gsubr ("blkid_evaluate_tag", 2, 0, 0, blkid_evaluate_tag_wrapper);
  scm_c_define_gsubr ("blkid_evaluate_spec", 1, 0, 0 blkid_evaluate_spec_wrapper);
}
