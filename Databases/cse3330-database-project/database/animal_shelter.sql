-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: May 02, 2019 at 05:05 AM
-- Server version: 5.7.24-log
-- PHP Version: 7.2.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `animal_shelter`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `ADMIN_ID` int(11) NOT NULL,
  `First_Name` varchar(100) NOT NULL,
  `Last_Name` varchar(100) NOT NULL,
  `Username` varchar(12) NOT NULL,
  `Pwd` varchar(12) NOT NULL,
  `Mobile_Number` varchar(12) NOT NULL,
  `Email` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`ADMIN_ID`, `First_Name`, `Last_Name`, `Username`, `Pwd`, `Mobile_Number`, `Email`) VALUES
(1000, 'Jerry', 'Olds', 'jdolds09', 'password', '817-944-4216', 'jdolds09@att.net');

-- --------------------------------------------------------

--
-- Table structure for table `adoption`
--

CREATE TABLE `adoption` (
  `PROFILE_ID` int(11) NOT NULL,
  `Adoption_Date` date NOT NULL,
  `Adoption_Fee` float NOT NULL,
  `ANIMAL_ID` int(11) NOT NULL,
  `First_Name` varchar(100) NOT NULL,
  `Last_Name` varchar(100) NOT NULL,
  `Animal_Name` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `adoption`
--

INSERT INTO `adoption` (`PROFILE_ID`, `Adoption_Date`, `Adoption_Fee`, `ANIMAL_ID`, `First_Name`, `Last_Name`, `Animal_Name`) VALUES
(9, '2019-05-01', 100, 2, 'David', 'Taylor', 'Christmas'),
(8, '2019-05-01', 300, 3, 'Nancy', 'Clark', 'Rufus'),
(3, '2019-05-01', 100, 5, 'Joe', 'Johnson', 'Teddy'),
(9, '2019-04-14', 300, 7, 'David', 'Taylor', 'Guido'),
(4, '2019-05-01', 200, 10, 'Bailey', 'Anderson', 'Duke'),
(6, '2019-05-01', 100, 11, 'Elizabeth', 'Williams', 'Andy'),
(2, '2019-05-01', 100, 14, 'Jane', 'Doe', 'Rango'),
(10, '2019-05-01', 100, 17, 'Hannah', 'Brown', 'Calvin'),
(1, '2019-05-01', 100, 19, 'Bill', 'Smith', 'Drogon'),
(7, '2019-05-01', 100, 20, 'Henry', 'Davis', 'Shiloh');

-- --------------------------------------------------------

--
-- Table structure for table `animal`
--

CREATE TABLE `animal` (
  `ANIMAL_ID` int(11) NOT NULL,
  `Description` varchar(100) NOT NULL,
  `Age` int(11) NOT NULL,
  `Name` varchar(100) NOT NULL,
  `Type` varchar(100) NOT NULL,
  `Breed` varchar(100) NOT NULL,
  `Size` varchar(6) NOT NULL,
  `Color` varchar(100) NOT NULL,
  `Availability` tinyint(1) NOT NULL,
  `Posted_Date` date NOT NULL,
  `Likes` int(11) NOT NULL,
  `Donation_Amount` float NOT NULL,
  `Adoption_Fee` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `animal`
--

INSERT INTO `animal` (`ANIMAL_ID`, `Description`, `Age`, `Name`, `Type`, `Breed`, `Size`, `Color`, `Availability`, `Posted_Date`, `Likes`, `Donation_Amount`, `Adoption_Fee`) VALUES
(1, 'Intelligent and happy puppy.', 2, 'Abby', 'Dog', 'Husky', 'Medium', 'Black and White', 1, '2019-03-14', 2, 25.75, 200),
(2, 'Mellow cat with pretty eyes.', 3, 'Christmas', 'Cat', 'American Short Hair', 'Small', 'Grey and Black', 0, '2019-03-16', 0, 12.63, 100),
(3, 'Lovable dog that loves to take naps.', 4, 'Rufus', 'Dog', 'Saint Bernard', 'Large', 'Brown and White', 0, '2019-03-25', 1, 9.05, 300),
(4, 'Talkative bird.', 1, 'Peter', 'Bird', 'Parrot', 'Small', 'Green', 1, '2019-03-25', 0, 10.25, 100),
(5, 'Quick turtle that loves to swim', 6, 'Teddy', 'Reptile', 'Red Eared Slider', 'Small', 'Green and Red', 0, '2019-03-25', 0, 17.05, 100),
(6, 'Black cat with green eyes.', 1, 'Shadow', 'Cat', 'Bombay', 'Small', 'Black', 1, '2019-03-25', 1, 0, 100),
(7, 'Snake that can grow to be as long as 6 feet.', 5, 'Guido', 'Reptile', 'Python', 'Large', 'Brown', 0, '2019-04-14', 0, 0, 300),
(8, 'Curious bird that loves to whistle.', 2, 'Charlie', 'Bird', 'Cockatiel', 'Small', 'Yellow', 1, '2019-04-14', 0, 10.15, 100),
(9, 'Constantly wants your attention.', 4, 'Tabby', 'Cat', 'Orange Tabby', 'Small', 'Orange', 1, '2019-04-20', 0, 45.89, 100),
(10, 'Good hunting dog.', 5, 'Duke', 'Dog', 'Golden Retriever', 'Medium', 'Golden', 0, '2019-04-20', 0, 65.3, 200),
(11, 'Likes to climb really high before taking a nap.', 3, 'Andy', 'Cat', 'British Shorthair', 'Small', 'Grey', 0, '2019-04-20', 2, 21.39, 100),
(12, 'Adventurous toad that can jump really far. ', 4, 'Slippy', 'Reptile', 'American Toad', 'Small', 'Brown', 1, '2019-04-20', 0, 20.15, 100),
(13, 'He likes to peck so be careful.', 2, 'Edgar', 'Bird', 'Raven', 'Small', 'Black', 1, '2019-05-01', 0, 0, 100),
(14, 'Very colorful pet.', 4, 'Rango', 'Reptile', 'Chameleon', 'Small', 'Many', 0, '2019-05-01', 0, 54.15, 100),
(15, 'Really big dog.', 5, 'Scooby', 'Dog', 'Great Dane', 'Large', 'Brown', 1, '2019-05-01', 0, 0, 300),
(16, 'Old dog that can still learn new tricks.', 7, 'Marshall', 'Dog', 'Black Lab', 'Medium', 'Black', 1, '2019-05-01', 0, 37.42, 200),
(17, 'Has really pretty blue eyes.', 3, 'Calvin', 'Cat', 'Siamese', 'Small', 'Black and White', 0, '2019-05-01', 0, 0, 100),
(18, 'Has a strong beak that he uses to climb', 2, 'Jamie', 'Bird', 'Cockatoo', 'Small', 'White', 1, '2019-05-01', 0, 63.21, 100),
(19, 'Named after Game of Thrones dragon.', 1, 'Drogon', 'Reptile', 'Bearded Dragon', 'Small', 'Tan', 0, '2019-05-01', 0, 0, 100),
(20, 'Likes to howl.', 5, 'Shiloh', 'Dog', 'Beagle', 'Small', 'Brown and White', 0, '2019-05-01', 0, 0, 100);

-- --------------------------------------------------------

--
-- Table structure for table `donations`
--

CREATE TABLE `donations` (
  `PROFILE_ID` int(11) NOT NULL,
  `Donation_Date` date NOT NULL,
  `Donation_Amount` float NOT NULL,
  `ANIMAL_ID` int(11) NOT NULL,
  `First_Name` varchar(100) NOT NULL,
  `Last_Name` varchar(100) NOT NULL,
  `Animal_Name` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `donations`
--

INSERT INTO `donations` (`PROFILE_ID`, `Donation_Date`, `Donation_Amount`, `ANIMAL_ID`, `First_Name`, `Last_Name`, `Animal_Name`) VALUES
(1, '2019-04-06', 25.75, 1, 'Bill', 'Smith', 'Abby'),
(4, '2019-04-14', 10.25, 4, 'Bailey', 'Anderson', 'Peter'),
(5, '2019-04-20', 15.3, 10, 'Tyler', 'Jones', 'Duke'),
(2, '2019-05-01', 20.15, 12, 'Jane', 'Doe', 'Slippy'),
(9, '2019-05-01', 50, 10, 'David', 'Taylor', 'Duke'),
(6, '2019-05-01', 37.42, 16, 'Elizabeth', 'Williams', 'Marshall'),
(7, '2019-05-01', 17.05, 5, 'Henry', 'Davis', 'Teddy'),
(8, '2019-05-01', 21.39, 11, 'Nancy', 'Clark', 'Andy'),
(3, '2019-05-01', 12.63, 2, 'Joe', 'Johnson', 'Christmas'),
(6, '2019-05-01', 40.4, 14, 'Elizabeth', 'Williams', 'Rango'),
(10, '2019-05-01', 9.05, 3, 'Hannah', 'Brown', 'Rufus'),
(8, '2019-05-01', 45.89, 9, 'Nancy', 'Clark', 'Tabby'),
(9, '2019-05-01', 63.21, 18, 'David', 'Taylor', 'Jamie'),
(4, '2019-05-01', 13.75, 14, 'Bailey', 'Anderson', 'Rango'),
(3, '2019-05-01', 10.15, 8, 'Joe', 'Johnson', 'Charlie');

-- --------------------------------------------------------

--
-- Table structure for table `inquiries`
--

CREATE TABLE `inquiries` (
  `INQUIRY_ID` int(11) NOT NULL,
  `PROFILE_ID` int(11) NOT NULL,
  `Inquiry_Date` date NOT NULL,
  `ANIMAL_ID` int(11) NOT NULL,
  `First_Name` varchar(100) NOT NULL,
  `Last_Name` varchar(100) NOT NULL,
  `Animal_Name` varchar(100) NOT NULL,
  `Question` varchar(150) NOT NULL,
  `Answer` varchar(150) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `inquiries`
--

INSERT INTO `inquiries` (`INQUIRY_ID`, `PROFILE_ID`, `Inquiry_Date`, `ANIMAL_ID`, `First_Name`, `Last_Name`, `Animal_Name`, `Question`, `Answer`) VALUES
(1, 1, '2019-03-25', 1, 'Bill', 'Smith', 'Abby', 'What kind of dog food does Abby like?', 'Purina Dog Chow Complete'),
(2, 2, '2019-04-06', 3, 'Jane', 'Doe', 'Rufus', 'How much does Rufus weigh?', NULL),
(3, 9, '2019-04-14', 7, 'David', 'Taylor', 'Guido', 'What is the lifespan of a Python like Guido?', NULL),
(4, 7, '2019-04-20', 12, 'Henry', 'Davis', 'Slippy', 'Does Slippy catch his food with his tounge?', NULL),
(5, 7, '2019-05-01', 2, 'Henry', 'Davis', 'Christmas', 'Why is Christmas named Christmas?', 'He was found and brought to the shelter on Christmas day.'),
(6, 10, '2019-05-01', 15, 'Hannah', 'Brown', 'Scooby', 'How tall is Scooby?', '30 inches'),
(7, 5, '2019-05-01', 16, 'Tyler', 'Jones', 'Marshall', 'Is Marshall a bird hunting dog?', 'Yes. He retrieves birds very well.'),
(8, 4, '2019-05-01', 6, 'Bailey', 'Anderson', 'Shadow', 'How many hours does Shadow normally sleep?', NULL),
(9, 6, '2019-05-01', 5, 'Elizabeth', 'Williams', 'Teddy', 'Where can I get a suitable environment for Teddy to live in?', NULL),
(10, 8, '2019-05-01', 8, 'Nancy', 'Clark', 'Charlie', 'How much does food for Charlie cost?', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `likes`
--

CREATE TABLE `likes` (
  `PROFILE_ID` int(11) NOT NULL,
  `ANIMAL_ID` int(11) NOT NULL,
  `First_Name` varchar(100) NOT NULL,
  `Last_Name` varchar(100) NOT NULL,
  `Animal_Name` varchar(100) NOT NULL,
  `Like_Date` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `likes`
--

INSERT INTO `likes` (`PROFILE_ID`, `ANIMAL_ID`, `First_Name`, `Last_Name`, `Animal_Name`, `Like_Date`) VALUES
(2, 6, 'Jane', 'Doe', 'Shadow', '2019-04-08'),
(1, 1, 'Bill', 'Smith', 'Abby', '2019-04-08'),
(4, 3, 'Bailey', 'Anderson', 'Rufus', '2019-04-14'),
(8, 11, 'Nancy', 'Clark', 'Andy', '2019-05-01'),
(10, 1, 'Hannah', 'Brown', 'Abby', '2019-05-01'),
(3, 11, 'Joe', 'Johnson', 'Andy', '2019-05-01');

-- --------------------------------------------------------

--
-- Table structure for table `profile`
--

CREATE TABLE `profile` (
  `PROFILE_ID` int(11) NOT NULL,
  `First_Name` varchar(100) NOT NULL,
  `Last_Name` varchar(100) NOT NULL,
  `Mobile_Number` varchar(12) NOT NULL,
  `Email` varchar(100) NOT NULL,
  `Username` varchar(12) NOT NULL,
  `Pwd` varchar(12) NOT NULL,
  `Join_Date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `profile`
--

INSERT INTO `profile` (`PROFILE_ID`, `First_Name`, `Last_Name`, `Mobile_Number`, `Email`, `Username`, `Pwd`, `Join_Date`) VALUES
(1, 'Bill', 'Smith', '817-123-4567', 'bill_smith@yahoo.com', 'bill_smith', 'password', '2019-03-04'),
(2, 'Jane', 'Doe', '817-987-6543', 'janedoe@gmail.com', 'jane_doe', 'password', '2019-03-04'),
(3, 'Joe', 'Johnson', '817-645-6160', 'joe_johnson@yahoo.com', 'joe_johnson', 'password', '2019-04-10'),
(4, 'Bailey', 'Anderson', '817-489-2112', 'bailey_anderson@hotmail.com', 'banderson', 'password', '2019-04-10'),
(5, 'Tyler', 'Jones', '817-156-3972', 'tyler_jones@att.net', 'tyler_jones', 'password', '2019-04-14'),
(6, 'Elizabeth', 'Williams', '817-481-5486', 'elizabeth_williams@gmail.com', 'ewilliams', 'password', '2019-04-14'),
(7, 'Henry', 'Davis', '817-564-4890', 'henry_davis@hotmail.com', 'henry_davis', 'password', '2019-04-14'),
(8, 'Nancy', 'Clark', '817-048-1991', 'nancy_clark@yahoo.com', 'nancy_clark', 'password', '2019-04-14'),
(9, 'David', 'Taylor', '817-489-9847', 'david_taylor@att.net', 'david_taylor', 'password', '2019-04-14'),
(10, 'Hannah', 'Brown', '817-494-2614', 'hannah_brown@gmail.com', 'hannah_brown', 'password', '2019-04-14');

-- --------------------------------------------------------

--
-- Table structure for table `transactions`
--

CREATE TABLE `transactions` (
  `Transaction_Date` date NOT NULL,
  `Transaction_Type` varchar(100) NOT NULL,
  `PROFILE_ID` int(11) NOT NULL,
  `First_Name` varchar(100) NOT NULL,
  `Last_Name` varchar(100) NOT NULL,
  `ANIMAL_ID` int(11) NOT NULL,
  `Animal_Name` varchar(100) NOT NULL,
  `Donation_Amount` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `transactions`
--

INSERT INTO `transactions` (`Transaction_Date`, `Transaction_Type`, `PROFILE_ID`, `First_Name`, `Last_Name`, `ANIMAL_ID`, `Animal_Name`, `Donation_Amount`) VALUES
('2019-03-25', 'Inquiry', 1, 'Bill', 'Smith', 1, 'Abby', NULL),
('2019-04-06', 'Inquiry', 2, 'Jane', 'Doe', 3, 'Rufus', NULL),
('2019-04-06', 'Donation', 1, 'Bill', 'Smith', 1, 'Abby', 25.75),
('2019-04-08', 'Like', 2, 'Jane', 'Doe', 6, 'Shadow', NULL),
('2019-04-08', 'Like', 1, 'Bill', 'Smith', 1, 'Abby', NULL),
('2019-04-14', 'Inquiry', 9, 'David', 'Taylor', 7, 'Guido', NULL),
('2019-04-14', 'Adoption', 9, 'David', 'Taylor', 7, 'Guido', NULL),
('2019-04-14', 'Like', 4, 'Bailey', 'Anderson', 3, 'Rufus', NULL),
('2019-04-14', 'Donation', 4, 'Bailey', 'Anderson', 4, 'Peter', 10.25),
('2019-04-20', 'Inquiry', 7, 'Henry', 'Davis', 12, 'Slippy', NULL),
('2019-04-20', 'Donation', 5, 'Tyler', 'Jones', 10, 'Duke', 15.3),
('2019-05-01', 'Donation', 2, 'Jane', 'Doe', 12, 'Slippy', 20.15),
('2019-05-01', 'Donation', 9, 'David', 'Taylor', 10, 'Duke', 50),
('2019-05-01', 'Donation', 6, 'Elizabeth', 'Williams', 16, 'Marshall', 37.42),
('2019-05-01', 'Inquiry', 7, 'Henry', 'Davis', 2, 'Christmas', NULL),
('2019-05-01', 'Donation', 7, 'Henry', 'Davis', 5, 'Teddy', 17.05),
('2019-05-01', 'Like', 8, 'Nancy', 'Clark', 11, 'Andy', NULL),
('2019-05-01', 'Donation', 8, 'Nancy', 'Clark', 11, 'Andy', 21.39),
('2019-05-01', 'Like', 10, 'Hannah', 'Brown', 1, 'Abby', NULL),
('2019-05-01', 'Inquiry', 10, 'Hannah', 'Brown', 15, 'Scooby', NULL),
('2019-05-01', 'Donation', 3, 'Joe', 'Johnson', 2, 'Christmas', 12.63),
('2019-05-01', 'Inquiry', 5, 'Tyler', 'Jones', 16, 'Marshall', NULL),
('2019-05-01', 'Donation', 6, 'Elizabeth', 'Williams', 14, 'Rango', 40.4),
('2019-05-01', 'Donation', 10, 'Hannah', 'Brown', 3, 'Rufus', 9.05),
('2019-05-01', 'Donation', 8, 'Nancy', 'Clark', 9, 'Tabby', 45.89),
('2019-05-01', 'Adoption', 4, 'Bailey', 'Anderson', 10, 'Duke', NULL),
('2019-05-01', 'Donation', 9, 'David', 'Taylor', 18, 'Jamie', 63.21),
('2019-05-01', 'Donation', 4, 'Bailey', 'Anderson', 14, 'Rango', 13.75),
('2019-05-01', 'Donation', 3, 'Joe', 'Johnson', 8, 'Charlie', 10.15),
('2019-05-01', 'Inquiry', 4, 'Bailey', 'Anderson', 6, 'Shadow', NULL),
('2019-05-01', 'Like', 3, 'Joe', 'Johnson', 11, 'Andy', NULL),
('2019-05-01', 'Adoption', 2, 'Jane', 'Doe', 14, 'Rango', NULL),
('2019-05-01', 'Adoption', 1, 'Bill', 'Smith', 19, 'Drogon', NULL),
('2019-05-01', 'Adoption', 9, 'David', 'Taylor', 2, 'Christmas', NULL),
('2019-05-01', 'Adoption', 7, 'Henry', 'Davis', 20, 'Shiloh', NULL),
('2019-05-01', 'Inquiry', 6, 'Elizabeth', 'Williams', 5, 'Teddy', NULL),
('2019-05-01', 'Adoption', 6, 'Elizabeth', 'Williams', 11, 'Andy', NULL),
('2019-05-01', 'Adoption', 10, 'Hannah', 'Brown', 17, 'Calvin', NULL),
('2019-05-01', 'Adoption', 8, 'Nancy', 'Clark', 3, 'Rufus', NULL),
('2019-05-01', 'Adoption', 3, 'Joe', 'Johnson', 5, 'Teddy', NULL),
('2019-05-01', 'Inquiry', 8, 'Nancy', 'Clark', 8, 'Charlie', NULL);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`ADMIN_ID`),
  ADD UNIQUE KEY `Username` (`Username`),
  ADD UNIQUE KEY `Mobile_Number` (`Mobile_Number`),
  ADD UNIQUE KEY `Email` (`Email`);

--
-- Indexes for table `adoption`
--
ALTER TABLE `adoption`
  ADD UNIQUE KEY `ANIMAL_ID` (`ANIMAL_ID`);

--
-- Indexes for table `animal`
--
ALTER TABLE `animal`
  ADD PRIMARY KEY (`ANIMAL_ID`);

--
-- Indexes for table `inquiries`
--
ALTER TABLE `inquiries`
  ADD PRIMARY KEY (`INQUIRY_ID`);

--
-- Indexes for table `profile`
--
ALTER TABLE `profile`
  ADD PRIMARY KEY (`PROFILE_ID`),
  ADD UNIQUE KEY `Mobile_Number` (`Mobile_Number`),
  ADD UNIQUE KEY `Email` (`Email`),
  ADD UNIQUE KEY `Username` (`Username`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `admin`
--
ALTER TABLE `admin`
  MODIFY `ADMIN_ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1001;

--
-- AUTO_INCREMENT for table `animal`
--
ALTER TABLE `animal`
  MODIFY `ANIMAL_ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;

--
-- AUTO_INCREMENT for table `inquiries`
--
ALTER TABLE `inquiries`
  MODIFY `INQUIRY_ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `profile`
--
ALTER TABLE `profile`
  MODIFY `PROFILE_ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `adoption`
--
ALTER TABLE `adoption`
  ADD CONSTRAINT `adoption_ibfk_1` FOREIGN KEY (`ANIMAL_ID`) REFERENCES `animal` (`ANIMAL_ID`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
