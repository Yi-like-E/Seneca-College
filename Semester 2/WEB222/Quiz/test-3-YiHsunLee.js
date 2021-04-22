//Question 1

function formatPath(obj) {
  const sep = obj.isWindows ? "\\" : "/";
  dir = obj.dir || ".";
  ext = obj.ext.startsWith(".") ? obj.ext : `.${obj.ext}`;
  return dir + sep + obj.filename + ext;
}

//Question 2

function Duration(value) {
  if (!value) {
    this.num = 0;
  }
  this.num = value;

  this.seconds = function (raw) {
    if (!raw) {
      if (this.num == 1) {
        return `${this.num} second`;
      }
      return `${this.num} seconds`;
    }
    return this.num;
  };

  this.minutes = function (raw) {
    let time = this.num / 60;
    if (!raw) {
      if (time < 1) {
        return `Less than a minute`;
      } else if (time == 1) {
        return `${time} minute`;
      }
      return `${time} minutes`;
    }
    return `${time}`;
  };

  this.hours = function (raw) {
    let time = this.num / 3600;
    if (!raw) {
      if (time < 1) {
        return `Less than an hour`;
      } else if (time == 1) {
        return `${time} hour`;
      }
      return `${time} hours`;
    }
    return `${time}`;
  };

  return this.num;
}

//Question 3 Part 1 (3 Marks)

function addColourPreference(user, str) {
  user["Colour Preference"] = str;
  return user;
}

//Question 3 Part 2 (3 Marks)

function removeColourPreference(user) {
  delete user["Colour Preference"];
  return user;
}
