const Pornsearch = require("pornsearch");
const Discord = require('discord.js');

// Boobsgif
module.exports = {
	name: 'boobsgif',
	description: 'Post a boob gif (Must be in NSFW channel).',
    async execute(message) 
    {
        // Check to see if command was sent in NSFW channel
        if(!message.channel.nsfw)
            message.channel.send("Must be in a NSFW channel.");
        else
        {
            try
            {
                // Get gif
                const Searcher = new Pornsearch("boob");
                const gifs = await Searcher.gifs();
                const result = Math.floor(Math.random() * gifs.length);
                const { url } = gifs[result - 1];

                // Embed gif
                const embed = new Discord.MessageEmbed()
                    .setImage(url)
                    .setColor("RANDOM")
                    .setURL(url)
                    .setAuthor(url);

                // Send gif
                return message.channel.send({embed});
            }
            catch(error)
            {
                console.log(error);
                return;
            }
        }
    },
};