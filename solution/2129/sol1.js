function capitalizeTitle(title: string): string {
    return title.split(' ').map(word => {
        if (word.length <= 2) {
            return word.toLowerCase();
        }
        return word.charAt(0).toUpperCase() + word.slice(1).toLowerCase();
    }).join(' ');
};
