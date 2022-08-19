import { Component, OnDestroy, OnInit } from '@angular/core';
import { AnyCatcher } from 'rxjs/internal/AnyCatcher';
import { ActivatedRoute } from '@angular/router';
import { MusicDataService } from '../music-data.service';
import { Subscription } from 'rxjs';

@Component({
  selector: 'app-artist-discography',
  templateUrl: './artist-discography.component.html',
  styleUrls: ['./artist-discography.component.css']
})
export class ArtistDiscographyComponent implements OnInit, OnDestroy {

  artistSub: any;
  albumsSub: any;
  albums: any;
  artist: any;
  id: any;

  constructor(private musicDataService: MusicDataService, private route: ActivatedRoute) {}

  ngOnInit(): void {
    this.id = this.route.snapshot.params['id'];
    this.artistSub = this.musicDataService.getArtistById(this.id).subscribe((data) => {
      return (this.artist = data);
    });

    this.albumsSub = this.musicDataService.getAlbumsByArtistId(this.id).subscribe((data) => {
      return (this.albums = data.items.filter(
        (item, index, self) =>
          self.findIndex(
            (t => t.name.toUpperCase() === item.name.toUpperCase())) === index
      ));
    });
  }

  ngOnDestroy() {
    this.albumsSub?.unsubscribe();
    this.artistSub?.unsubscribe();
  }
}

