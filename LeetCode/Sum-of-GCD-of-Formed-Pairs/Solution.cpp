        mx = []
        prefixMax = -inf

        for x in nums:
            prefixMax = max(prefixMax, x)
            mx.append(prefixMax)

        prefixGcd = [gcd(x, y) for x, y in zip(nums, mx)]