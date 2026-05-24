namespace Hospital_Management_System.Models
{
    /// <summary>
    /// Represents personal details of a patient.
    /// </summary>
    public class PatientData
    {
        private string _name;
        private string _fatherName;
        private int _age;
        private string _phone;
        private string _gender;

        /// <summary>
        /// Gets or sets the patient's full name.
        /// </summary>
        public string Name
        {
            get { return _name; }
            set { _name = value; }
        }

        /// <summary>
        /// Gets or sets the patient's father's name.
        /// </summary>
        public string FatherName
        {
            get { return _fatherName; }
            set { _fatherName = value; }
        }

        /// <summary>
        /// Gets or sets the patient's age.
        /// </summary>
        public int Age
        {
            get { return _age; }
            set { _age = value; }
        }

        /// <summary>
        /// Gets or sets the patient's phone number.
        /// </summary>
        public string Phone
        {
            get { return _phone; }
            set { _phone = value; }
        }

        /// <summary>
        /// Gets or sets the patient's gender.
        /// </summary>
        public string Gender
        {
            get { return _gender; }
            set { _gender = value; }
        }

        /// <summary>
        /// Initializes a new instance of the PatientData class with default values.
        /// </summary>
        public PatientData()
        {
            _name = string.Empty;
            _fatherName = string.Empty;
            _age = 0;
            _phone = string.Empty;
            _gender = string.Empty;
        }

        /// <summary>
        /// Initializes a new instance of the PatientData class with specified details.
        /// </summary>
        /// <param name="name">The patient's full name.</param>
        /// <param name="fatherName">The patient's father's name.</param>
        /// <param name="age">The patient's age.</param>
        /// <param name="phone">The patient's phone number.</param>
        /// <param name="gender">The patient's gender.</param>
        public PatientData(string name, string fatherName, int age, string phone, string gender)
        {
            _name = name;
            _fatherName = fatherName;
            _age = age;
            _phone = phone;
            _gender = gender;
        }
    }
}
