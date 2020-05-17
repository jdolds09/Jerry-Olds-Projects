<!DOCTYPE html>
<html>
	<head>
        <style>
            input[type = "date"]
            {
                margin-bottom: 20px;
	            padding: 5px;
	            height: 25px;
	            width: 250px;
	            float: center;
            }
        </style>
		<meta charset="utf-8">
		<meta name= "viewport" content="width=device-width">
		<meta name= "descriptions" content="User friendly online animal shelter">
		<meta name= "keywords" content="animal, shelter, animal shelter, dogs, cats, adoption, donation, pets">
		<meta name= "author" content="Donovan Almendariz, Jerry Olds">
		<title>Animal Shelter | Donate</title>
		<link rel="stylesheet" href= "./style.css">
	</head>
	<body>

		<header>
			<div class= "container">
				<div id= "branding">
					<h1><span class= "highlight">DJ's</span> Animal Shelter</h1>
				</div>
				<nav>
					<ul>
						<li><a href= "user_home.php">Home</a></li>
                        <li><a href = "animals.php">Animals</a></li>
						<li><a href = "user_inquiries.php">Inquiries</a></li>
                        <li><a href = "profile.php">Profile</a></li>
						<li><a href= "about.php">About</a></li>
					<!--Sign Out-->
                        <li><a href= "?sign_out" >Sign Out</a></li>
                        <?php
						// Sign out
                            if(isset($_GET['sign_out']))
                            {
                            // Set active_user to NULL
                                session_start();
                                $_SESSION['active_user_id'] = NULL;
                            // Re-direct to index page
                                header('Location: index.php');
                            }
                        ?>
					</ul>
				</nav>
			</div>
		</header>

		<section id= "Create2">
			<div class="container">
				<div class="dark">
					<form method = "post" action = "">
					
						<h1>Donate</h1>

						<div class="form-input">
							<input type="text" name ="credit_card" placeholder="Credit Card Number"/>	
						</div>

						<div class="form-input">
							<input type="text" name ="cvc" placeholder="CVC"/>
						</div>

                        <div class="form-input">
							<input type="date" name ="exp_date" placeholder="Expiration Date"/>
						</div>

                        <div class = "form-input">
                            <input type="number" step =".01" name ="amount" placeholder="Donation Amount"/>
                        </div>

						<input type="submit" name="submit" class = "button_1" value = "DONATE"/>

					</form>
				</div>
			</div>	
		</section>

		<footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

<!--Sending adoption data to database-->
<?php
// TODO(optional): Add some sort of input validation if we have the time
	if(isset($_POST['submit']) && !empty($_POST['submit']))
	{
    
    // The information the user fills out to adopt the pet is all
    // uneeded at the moment. The requirements in the project say
    // that the user fills out a form to adopt the pet. So currently the  
    // user fills out an arbitrary form before adopting. If we come up with
    // some kind of use for this information we could use it later (probably won't).
    
    /*
		$credit_card = $_POST['credit_card'];
        $cvc = $_POST['cvc'];
        $exp_date = $_POST['exp_date'];
    */
    
    // Connect to database
        include('connection.php');

     // Variables
        session_start();
        $profile_id = $_SESSION['active_user_id'];
        $animal_id = $_SESSION['animal_id'];
        $amount = $_POST['amount'];
        $query = mysqli_query($con, "SELECT Donation_Amount FROM animal WHERE ANIMAL_ID = '$animal_id'");
        $query2 = mysqli_query($con, "SELECT First_Name, Last_Name FROM profile WHERE PROFILE_ID = '$profile_id'");
        $query3 = mysqli_query($con, "SELECT Name FROM animal WHERE ANIMAL_ID = '$animal_id'");
        $row = $query->fetch_assoc();
        $row2 = $query2->fetch_assoc();
        $row3 = $query3->fetch_assoc();
        $donation_amount = $row['Donation_Amount'];
        $fname = $row2['First_Name'];
        $lname = $row2['Last_Name'];
        $animal_name = $row3['Name'];

    // Send donation to database
        $sql = "INSERT INTO donations (PROFILE_ID, Donation_Date, Donation_Amount, ANIMAL_ID, First_Name, Last_Name, Animal_Name)
				VALUES ('$profile_id', NOW(), '$amount', '$animal_id', '$fname', '$lname', '$animal_name')";
				
	// Send donation to transactions
		$sql2 = "INSERT INTO transactions (Transaction_Date, Transaction_Type, PROFILE_ID, First_Name, Last_Name, ANIMAL_ID, Animal_Name, Donation_Amount)
				 VALUES (NOW(), 'Donation', '$profile_id', '$fname', '$lname', '$animal_id', '$animal_name', '$amount')";
    
	// Update animal donation amount
		$sql3 = "UPDATE animal SET Donation_Amount = ('$donation_amount' +'$amount') WHERE ANIMAL_ID = '$animal_id'";
                
	// Unsuccessful entry in to database
		if(!mysqli_query($con, $sql) || !mysqli_query($con, $sql2) || !mysqli_query($con, $sql3))
			header('Location: error.php');

	// Successful entry in to database
        else
        {
        // Disconnect from database
            mysqli_close($con);
        // Redirect to successful adoption page
            header('Location: donated.php');
        }
	}
?>

	</body>
</html>