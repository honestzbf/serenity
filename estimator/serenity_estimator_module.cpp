#include <mesos/mesos.hpp>
#include <mesos/module.hpp>

#include <mesos/module/resource_estimator.hpp>

#include <mesos/slave/resource_estimator.hpp>

#include <stout/try.hpp>

#include <string>

#include "estimator/serenity_estimator.hpp"

// TODO(nnielsen): Break up into explicit using-declarations instead.
using namespace mesos;  // NOLINT(build/namespaces).

using mesos::serenity::SerenityEstimator;

using mesos::slave::ResourceEstimator;

static ResourceEstimator* createSerenityEstimator(
    const Parameters& parameters) {
  LOG(INFO) << "Loading Serenity Estimator module";
  Try<ResourceEstimator*> result = SerenityEstimator::create(None());
  if (result.isError()) {
    return NULL;
  }
  return result.get();
}


mesos::modules::Module<ResourceEstimator>
com_mesosphere_mesos_SerenityEstimator(
    MESOS_MODULE_API_VERSION,
    MESOS_VERSION,
    "Mesosphere",
    "support@mesosphere.com",
    "Serenity Estimator",
    NULL,
    createSerenityEstimator);
