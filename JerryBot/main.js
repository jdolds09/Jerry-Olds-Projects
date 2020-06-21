const fs = require('fs')
const Discord = require('discord.js');
const Client = require('./client/Client');

prefix = '!';

const client = new Client();
client.commands = new Discord.Collection();

const command_files = fs.readdirSync('./commands').filter(file => file.endsWith('.js'));
for (const file of command_files)
{
    const command = require(`./commands/${file}`);
    client.commands.set(command.name, command);
}

client.once('ready', () => {
    console.log("JerryBot is online!");
});

client.on('message', async message => {
	const args = message.content.slice(prefix.length).split(/ +/);
	const commandName = args.shift().toLowerCase();
	const command = client.commands.get(commandName);

	if (message.author.bot) return;
	if (!message.content.startsWith(prefix)) return;

    try 
    {
        command.execute(message);
    } 
    catch (error) 
    {
		console.error(error);
		message.reply('There was an error trying to execute that command!');
	}
});

client.login(process.env.token);