var numJewelsInStones = function (J, S) {
	const jewelsSet = new Set(J.split(""));
	return S.split("").reduce((prev, val) => {
		return prev + jewelsSet.has(val);
	}, 0);
};
