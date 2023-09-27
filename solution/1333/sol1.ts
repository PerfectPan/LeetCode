function filterRestaurants(restaurants: number[][], veganFriendly: number, maxPrice: number, maxDistance: number): number[] {
    return restaurants
            .filter(([, , vegan, price, distance]) => (!veganFriendly || vegan) && price <= maxPrice && distance <= maxDistance)
            .sort((a, b) => {
                if (a[1] == b[1]) {
                    return b[0] - a[0];
                }
                return b[1] - a[1];
            })
            .map(([id]) => id);
};
