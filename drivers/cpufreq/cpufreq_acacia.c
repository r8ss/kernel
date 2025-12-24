/*
 *  linux/drivers/cpufreq/cpufreq_acacia.c
 *
 *  'acacia' - A max performance governor that forces maximum CPU frequency
 */

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/cpufreq.h>
#include <linux/init.h>
#include <linux/module.h>

static void cpufreq_gov_acacia_limits(struct cpufreq_policy *policy)
{
	pr_debug("acacia: forcing max frequency %u kHz\n", policy->max);
	__cpufreq_driver_target(policy, policy->max, CPUFREQ_RELATION_H);
}

static struct cpufreq_governor cpufreq_gov_acacia = {
	.name		= "acacia",
	.owner		= THIS_MODULE,
	.limits		= cpufreq_gov_acacia_limits,
};

static int __init cpufreq_gov_acacia_init(void)
{
	return cpufreq_register_governor(&cpufreq_gov_acacia);
}

static void __exit cpufreq_gov_acacia_exit(void)
{
	cpufreq_unregister_governor(&cpufreq_gov_acacia);
}

#ifdef CONFIG_CPU_FREQ_DEFAULT_GOV_ACACIA
struct cpufreq_governor *cpufreq_default_governor(void)
{
	return &cpufreq_gov_acacia;
}
#endif

fs_initcall(cpufreq_gov_acacia_init);
module_exit(cpufreq_gov_acacia_exit);
